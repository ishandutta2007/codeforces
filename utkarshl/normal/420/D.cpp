#include"stdio.h"
#include"cassert"
#define M 1000000
#define N 1000000
#define DEBUG(x) ;
//printf x;

struct node {
	int color;
	int inc;
	node(): color(-1), inc(0) {}
} BIT[N+M+2];

int used[N+1];

int lower_power_of_two(int i) {
	i --;
	i |= (i>>1);
	i |= (i>>2);
	i |= (i>>4);
	i |= (i>>8);
	i |= (i>>16);
	return (i+1)>>1;
}

int n, m;

void increment_bit(int pos, int inc) {
	while (pos <= m+n){
		BIT[pos].inc += inc;
		pos += (pos & -pos);
	}
}

int binary_search(int low, int hi, int sum) {
	DEBUG(("binary search %d - %d for %d\n", low, hi, sum))
	assert(sum>0 and hi+1-low >= sum and low<=hi);
	if (low == hi) {
		assert(sum>0);
		return low;
	}
	int mid = lower_power_of_two(hi-(low-1)) + low-1;
	if(BIT[mid].inc < sum) {
		sum -= BIT[mid].inc;
		low = mid+1;
	} else {
		hi = mid;
	}
	return binary_search(low, hi, sum);
}

int binary_search(int sum) {
	// search for first position with prefix_sum = sum, i.e. locate teh sum^th glass in current queue
	int lower = 1, higher = n+m;
	return binary_search(lower, higher, sum);
}

int main() {
	scanf("%d%d", &n, &m);
	int front = m; // all glasses are at indices front+1, front + 2, ... m+n at any time
	for(int i=0; i<n; i++)
		increment_bit(m+1+i, 1);
	while(front>0) {
		int x, y;
		scanf("%d%d", &x, &y);
		int bit_pos = binary_search(y);
		DEBUG(("%d th cup is at pos %d\n", y, bit_pos));
		if (BIT[bit_pos].color<0) {
			BIT[bit_pos].color = x;
		} else if (BIT[bit_pos].color != x) {
			printf("-1");
			return 0;
		}
		increment_bit(front, 1); // place a glass here
		increment_bit(bit_pos, -1); // remove the glass from here
		BIT[front].color = BIT[bit_pos].color; //copy the color information
		front --;
	}
	for(int i=m+1; i<=m+n; i++) {
		if (BIT[i].color>0) {
			if(used[BIT[i].color]) {
				printf("-1\n");
				return 0;
			}
			used[BIT[i].color] = 1;
		}
	}
	for(int i=m+1, next_free_color = 1; i<=m+n; i++) {
		if (BIT[i].color>0) {
			printf("%d ", BIT[i].color);
		} else {
			while(used[next_free_color]) next_free_color++;
			printf("%d ", next_free_color++);
		}
	}
}