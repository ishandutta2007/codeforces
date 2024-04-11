#include<iostream>
#include<algorithm>
using namespace std;

#include<string.h>
#include<math.h> 

#define N 400010

#define inf 0x7fffffff


int tree[N];
int lazy[N]={0};

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    		tree[node] = 0; // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {
  
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] += value;

		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return -inf; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result
	
	return res;
}

// int main() {
// 	for(int i = 0; i < N; i++) arr[i] = 1;

// 	build_tree(1, 0, N-1);

// 	memset(lazy, 0, sizeof lazy);

// 	update_tree(1, 0, N-1, 0, 6, 5); // Increment range [0, 6] by 5. here 0, N-1 represent the current range.
// 	update_tree(1, 0, N-1, 7, 10, 12); // Incremenet range [7, 10] by 12. here 0, N-1 represent the current range.
// 	update_tree(1, 0, N-1, 10, N-1, 100); // Increment range [10, N-1] by 100. here 0, N-1 represent the current range.

// 	cout << query_tree(1, 0, N-1, 0, N-1) << endl; // Get max element in range [0, N-1]
// }

int oper[200000];
int arr[200000];

int checkhighest(int m){
	int high=m-1;
	int low=0;
	int mid=(low+high)/2;
	int ans=-1;
	while(low<=high){
		if(query_tree(1,0,m-1,mid,m-1)>0){
			low=mid+1;
			ans=mid;
		}
		else {
			high=mid-1;
		}
		mid=(low+high)/2;
	}
	if(ans==-1){
		cout<<-1<<endl;
	}
	else{
		cout<<arr[ans]<<endl;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	int m,i,p,t;
	cin>>m;
		build_tree(1, 0, m-1);
	for(i=0;i<m;i++){
		cin>>p;
		p--;
		cin>>t;
		if(t==1){
			//cin>>p;
			oper[p]=1;
			cin>>arr[p];
			update_tree(1,0,m-1,0,p,1);
		}
		else{
			oper[p]=-1;
			update_tree(1,0,m-1,0,p,-1);
		}
		checkhighest(m);
	}
}