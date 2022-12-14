#include<cstdio>
#include<utility>
#include<map>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<long long,long long> P;

P ps[200200];
int ln;

set<P> ma_se;

long long det(long long a,long long b,long long c,long long d){
	return a*d-b*c;
}

bool check(P p1,P p2,P p3){
	long long dx1=p1.first-p2.first;
	long long dy1=p1.second-p2.second;
	long long dx2=p3.first-p2.first;
	long long dy2=p3.second-p2.second;
	return det(dx1,dy1,dx2,dy2)>=0;
}

vector<P> vec;

map<int,int> mp;

void get_conv(){
	ln=0;
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		ps[ln++]=P(it->first,it->second);
	}
	for(int i=0;i<ln;i++){
		while(vec.size()>=1){
			P p2=vec.back();
			P p3=ps[i];
			if(p2.first<p3.first&&p2.second<p3.second){
				vec.pop_back();
			}else{
				break;
			}
		}
		while(vec.size()>1){
			P p1=vec[vec.size()-2];
			P p2=vec[vec.size()-1];
			P p3=ps[i];
			bool flg=check(p1,p2,p3);
			if(!flg){
				vec.pop_back();
			}else{
				break;
			}
		}
		vec.push_back(ps[i]);
	}
}

bool solve(){
	get_conv();
	for(set<P>::iterator it=ma_se.begin();it!=ma_se.end();it++){
		P p=*it;
		if(p.first==vec.back().first) return true;
	}
	for(int i=0;i<vec.size();i++){
		set<P>::iterator it=ma_se.find(vec[i]);
		if(it!=ma_se.end()) return true;
	}
	return false;
}

void input(){
	int N,M;
	scanf("%d%d",&N,&M);
	ln=N+M;
	int x,y;
	scanf("%d%d",&x,&y);
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ma_se.insert(P(x,y));
		ps[i]=P(x,y);
		mp[x]=max(mp[x],y);
	}
	for(int i=0;i<M;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ps[i+N]=P(x,y);
		mp[x]=max(mp[x],y);
	}
}

int main(){
	input();
	bool flg=solve();
	if(flg) printf("Max\n");
	else printf("Min\n");
	return 0;
}