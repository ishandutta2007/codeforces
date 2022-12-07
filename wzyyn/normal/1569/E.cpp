#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;

const int mo=998244353;
int vpow[35],hson[35],key[35],val[35];
int k,A,h,m;
vector<pair<int,int> > m1,m2,m3,m4;
void Construct(int fir,int msk){
	for (int j=1;j<m;j++)
		hson[j]=(msk>>(j-1))&1;
	val[1]=fir;
	for (int j=1;j<m;j++){
		val[j*2+hson[j]]=val[j];
		val[j*2+1-hson[j]]=key[j];
	}
	for (int j=m;j<2*m;j++)
		printf("%d ",val[j]);
}
int main(){
	scanf("%d%d%d",&k,&A,&h);
	vpow[0]=1;
	for (int i=1;i<=32;i++)
		vpow[i]=1ll*vpow[i-1]*A%mo;
	for (int i=1;i<16;i<<=1)
		for (int j=i;j<2*i;j++)
			key[j]=2*i+1;
	m=1<<(k-1);
	for (int i=0;i<1<<(m-1);i++){
		for (int j=1;j<m;j++)
			hson[j]=(i>>(j-1))&1;
		val[1]=2;
		for (int j=1;j<m;j++){
			val[j*2+hson[j]]=val[j];
			val[j*2+1-hson[j]]=key[j];
		}
		long long s1=0,s2=0,s3=0,s4=0;
		for (int j=0;j<m;j++){
			s1+=1ll*vpow[(val[j+m]==2?1:val[j+m])]*(j+1);
			s2+=1ll*vpow[(val[j+m]==2?2:val[j+m])]*(j+1);
			s3+=1ll*vpow[(val[j+m]==2?1:val[j+m])]*(j+1+m);
			s4+=1ll*vpow[(val[j+m]==2?2:val[j+m])]*(j+1+m);
		}
		m1.push_back(pair<int,int>(s1%mo,i));
		m2.push_back(pair<int,int>(s2%mo,i));
		m3.push_back(pair<int,int>(s3%mo,i));
		m4.push_back(pair<int,int>(s4%mo,i));
	}
	sort(m2.begin(),m2.end());
	sort(m4.begin(),m4.end());
	for (auto i:m1){
		int v=(h+mo-i.first)%mo;
		int p=lower_bound(m4.begin(),m4.end(),pair<int,int>(v,0))-m4.begin();
		if (p==m4.size()||m4[p].first!=v) continue;
		Construct(1,i.second);
		Construct(2,m4[p].second);
		return 0;
	}
	for (auto i:m3){
		int v=(h+mo-i.first)%mo;
		int p=lower_bound(m2.begin(),m2.end(),pair<int,int>(v,0))-m2.begin();
		if (p==m2.size()||m2[p].first!=v) continue;
		Construct(2,m2[p].second);
		Construct(1,i.second);
		return 0;
	}
	puts("-1");
}