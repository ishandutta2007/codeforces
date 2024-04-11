#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	if (a>b) swap(a,b);
	int f=0;
	int res=0;
	while (a<b)
	{
		f++;
		a+=1;
		res+=f;
		if (a<b) {b-=1;res+=f;}
		}
    cout<<res<<endl;
}