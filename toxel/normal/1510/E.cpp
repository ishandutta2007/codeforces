#include <bits/stdc++.h>

const double eps = 1e-7;
const double inf = 1e20;
const double three = 1. / 3.;

int n;
double x,y;
std::map< std::pair<double,double>,int > mp[20];

void print(int tmp1,int tmp2) {
	for (int i = 0; i < n/2; i++) 
		if (tmp1 & (1<<i))
			printf("(");
		else 
			printf(")");
	for (int i = n/2 - 1; i >= 0; i--) 
		if (tmp2 & (1<<i))
			printf(")");
		else 
			printf("(");
	printf("\n");
	exit(0);
} 

void check(double x1,double y1,double S,int pos,int tmp) {
	x1 += x * S;
	x1 /= S;
	x1 = 1. * n -x1;
	x1 *= S;
	x1 -= x * S;
	x1 = -x1;
	y1 = - y1;
	
	for (auto it = mp[pos].lower_bound( {x1-eps,-inf} ) ; it != mp[pos].end() &&  it -> first.first < x1 + eps ; it++) if ( fabs(y1 - it -> first.second) < eps ) {
		print( it->second,tmp );
	}
}

void dfs(int now,int pos,int tmp,bool flag) {

	if (now == n/2) {
		double x1, y1;
		double S;
		x1 = y1 = S = 0.;
		int l = 0;

		for (int i = 0; i < n/2; i++) {
			int r = l;
			if ((tmp>>i)&1) r++;
			else r--;

			x1 += three * (r-l) * (i+1) * (i+1) * (i+1)
					- three * (r-l) * i * i * i
					+ .5 * (l - (r-l)*i) * (i+1) * (i+1)
					- .5 * (l - (r-l)*i) * i * i;

			y1 += .5 * (r-l)*(r-l) * three * ( (i+1)*(i+1)*(i+1) - i*i*i )
					+ 1. * (r-l) * (l-i*(r-l)) * .5 * ((i+1)*(i+1) - i*i)
					+ .5 * (l - i*(r-l)) * (l - i*(r-l));

			S += .5 * (l+r);

			l = r;
		}

		x1 -= x*S;
		y1 -= y*S;


		if (flag == 0) {
			mp[pos][{x1,y1}]=tmp; 
		}
		else {
			check(x1,y1,S,pos,tmp);
		}
		return ;
	}

	if (pos > 0) dfs(now + 1, pos - 1,tmp, flag);
	dfs(now + 1, pos + 1, tmp + (1<<now), flag);
}


int main() {
	scanf("%d%lf%lf",&n,&x,&y);
	dfs(0,0,0,0);
	dfs(0,0,0,1);
	return 0;
}