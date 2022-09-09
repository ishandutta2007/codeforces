#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1050;
int c[N],r[N];
set<pair<int,int>> st;
bool Check(int x, int y)
{
	if(x<1 || y<1 || x>999 || y>999) return 1;
	if(st.count(mp(x,y))) return 1;
	if(r[x] || c[y]) return 0;
	return 1;
}
int x[N],y[N];
int main()
{
	int n,i,j,a,b;
	scanf("%i %i",&a,&b);
	for(i=1;i<667;i++) scanf("%i %i",&x[i],&y[i]),st.insert(mp(x[i],y[i]));
	int t=2000;
	for(i=1;i<667;i++) r[x[i]]++,c[y[i]]++;
	int phase=1;
	while(t--)
	{
		bool ok=0;
		for(i=-1;i<=1;i++)
		{
			for(j=-1;j<=1;j++)
			{
				if(i!=0 || j!=0)
				{
					if(!Check(a+i,b+j))
					{
						printf("%i %i\n",a+i,b+j);
						fflush(stdout);
						ok=1;
						a+=i;b+=j;
						break;
					}
				}
			}
			if(ok) break;
		}
		if(!ok)
		{
			if(a==999 && b==999) phase=0;
			if(phase==0 && a==500 && b==500) phase=2;
			if(phase==1)
			{
				if(a<999) a++;
				if(b<999) b++;
				printf("%i %i\n",a,b);
				fflush(stdout);
			}
			else if(phase==0)
			{
				a--;b--;
				printf("%i %i\n",a,b);
				fflush(stdout);
			}
			else
			{
				a--;b++;
				printf("%i %i\n",a,b);
				fflush(stdout);
			}
		}
		int k,nx,ny;
		scanf("%i %i %i",&k,&nx,&ny);
		if(k==-1) return 0;
		r[x[k]]--;c[y[k]]--;
		st.erase(mp(x[k],y[k]));
		x[k]=nx;
		y[k]=ny;
		r[x[k]]++;c[y[k]]++;
		st.insert(mp(x[k],y[k]));
	}
	return 0;
}