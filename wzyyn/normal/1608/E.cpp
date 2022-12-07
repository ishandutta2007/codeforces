#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int n;
struct node{
	int x,y,c;
	bool operator <(const node &a)const{
		return x<a.x;
	}
};
node a[N],b[N];

bool check(int c1,int c2,int c3,int mid){
	int s1=0,s2=0,s3=0;
	int p1=0,p2=0,p3=0;
	for (int i=1;i<=n;i++)
		if (a[i].c==c1)
			if ((++s1)==mid){
				p1=a[i].x;
				break;
			}
	if (s1!=mid)
		return 0;
	for (int i=1;i<=n;i++)
		if (b[i].y>p1)
			if (b[i].c==c2)
				if ((++s2)==mid){
					p2=b[i].x;
					break;
				}
	if (s2!=mid)
		return 0;
	for (int i=1;i<=n;i++)
		if (b[i].y>p1&&b[i].x>p2)
			if (b[i].c==c3) ++s3;
	return s3>=mid;
}
bool check2(int c1,int c2,int c3,int mid){
	int s1=0,s2=0,s3=0;
	int p1=0,p2=0,p3=0;
	for (int i=1;i<=n;i++)
		if (a[i].c==c1)
			if ((++s1)==mid){
				p1=a[i].x;
				break;
			}
	if (s1!=mid)
		return 0;
	for (int i=1;i<=n;i++)
		if (a[i].x>p1)
			if (a[i].c==c2)
				if ((++s2)==mid){
					p2=a[i].x;
					break;
				}
	if (s2!=mid)
		return 0;
	for (int i=1;i<=n;i++)
		if (a[i].x>p2)
			if (a[i].c==c3)
				++s3;
	return s3>=mid;

}
int check(){
	for (int i=1;i<=n;i++){
		b[i]=a[i];
		swap(b[i].x,b[i].y);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int l=1,r=n/3,ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(1,2,3,mid)||
			check(1,3,2,mid)||
			check(2,1,3,mid)||
			check(2,3,1,mid)||
			check(3,1,2,mid)||
			check(3,2,1,mid))
				ans=mid,l=mid+1;
		else if (check2(1,2,3,mid)||
				 check2(1,3,2,mid)||
				 check2(2,1,3,mid)||
				 check2(2,3,1,mid)||
				 check2(3,1,2,mid)||
				 check2(3,2,1,mid))
					ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
	int ans=0;
	ans=max(ans,check());
	for (int i=1;i<=n;i++) a[i].x*=-1;
	ans=max(ans,check());
	for (int i=1;i<=n;i++) swap(a[i].x,a[i].y);
	ans=max(ans,check());
	for (int i=1;i<=n;i++) a[i].x*=-1;
	ans=max(ans,check());
	cout<<ans*3<<endl;
}