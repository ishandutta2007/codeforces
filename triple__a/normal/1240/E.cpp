#include<bits/stdc++.h>
using namespace std;

const int maxm=500000;

int s[maxm+7],n;
long long pre[maxm+7];

void pre_calc(){
	for (int i=1;i<=maxm;++i){
		pre[i]=0;
		int j=1;
		while (j*i<=maxm){
			pre[i]+=1LL*(j-1)*(s[i*j-1]-s[max((j-1)*i-1,0)]);
//			cout<<pre[i]<<" ";
			++j;
		}
		pre[i]+=(s[maxm]-s[(j-1)*i-1])*(j-1);
//		cout<<pre[i]<<endl;
	}
}

int ck(int y,int x){
	int j=1,ans=0,z=x%y;
	while (j*y<=maxm){
		if (y*j<=x){
			j++;
			continue;
		}
		ans+=s[y*j-1]-s[y*(j-1)+z-1];
		j++;
	}
	ans+=s[maxm]-s[min(maxm,y*(j-1)+z-1)];
	return ans;
}

bool get1(int x,int y){
	if (s[maxm]-s[min(2*x-1,maxm)]<1) return 0;
//	cout<<pre[y]<<" "<<ck(y,2*x)<<endl;
	if (pre[y]<x+((2*x)/y)+max(1-ck(y,2*x),0)) return 0;
	return 1;
}

bool get2(int x,int y){
	if (s[maxm]-s[x-1]<2) return 0;
//	cout<<pre[y]<<" "<<ck(y,x)<<endl;
	if (pre[y]<x+2*(x/y)+max(2-ck(y,x),0)) return 0;
	return 1;
}

int mid_search(int l,int r,int y){
	if (l==r) return l;
	int md=(l+r)>>1;
//	cout<<l<<" "<<r<<" "<<y<<" "<<get1(md+1,y)<<" "<<get2(md+1,y)<<endl;
	if (get1(md+1,y)||get2(md+1,y)){
		return mid_search(md+1,r,y);
	}
	else{
		return mid_search(l,md,y);
	}
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		int u;
		scanf("%d",&u);
		s[u]++;
	}
	for (int i=1;i<=maxm;++i){
		s[i]+=s[i-1];
	}
	pre_calc();
//	cout<<get1(5,4)<<" "<<get2(5,4)<<endl;
	long long ans=0;
	for (int i=2;i<=maxm;++i){
		if (!get1(2,i)&&!get2(2,i)) break;
		ans=max(ans,1LL*i*mid_search(2,maxm,i));
	}
	cout<<ans<<endl;
	return 0;
}