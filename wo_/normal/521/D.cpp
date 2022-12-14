#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

struct Frac{
	long long num,den;
	Frac(){}
	Frac(long long a,long long b):num(a),den(b){
		if(den<0){
			num*=-1;
			den*=-1;
		}
	}
};

bool operator<(const Frac &f1,const Frac &f2){
	long long a=f1.num,c=f2.num;
	long long b=f1.den,d=f2.den;
	if(a==0) return 0<b;
	if(b==0) return a<0;
	if((a>0)!=(b>0)) return a<b;
	if(a<0){
		Frac f1_=f1,f2_=f2;
		f1_.num*=-1;
		f2_.num*=-1;
		return !(f1_<f2_);
	}
	//a,b,c,d>0
	if(a==c){
		return b>d;
	}
	if(b==d){
		return a<c;
	}
	if((a>c)!=(b>d)){
		return a<c;
	}
	if(a<c){
		return !(f2<f1);
	}
	long long x=b/d;
	long long y=b-x*d;//b=x*d+y
	long long z=a/c;
	long long w=a-z*c;//a=z*c+w
	if(x!=z){
		return z<x;
	}
	if(y==0) return false;
	Frac tmp=Frac(w,y);
	return tmp<f2;
}

typedef pair<int,int> P;

int ini[100100];
P ass[100100];
vector<P> ad[100100];
vector<P> mult;

typedef pair<Frac,int> Item;

vector<Item> items;

int K,N,M;

bool need[100100];
int ts[100100];
int ans=-1;

int main(){
	scanf("%d%d%d",&K,&N,&M);
	for(int i=0;i<K;i++){
		scanf("%d",ini+i);
	}
	for(int i=0;i<N;i++){
		int t,id,b;
		scanf("%d%d%d",&t,&id,&b);
		ts[i]=t;
		id--;
		if(t==1){//ass
			ass[id]=max(ass[id],P(b,i));
		}else if(t==2){//add
			ad[id].push_back(P(b,i));
		}else{//mult
			mult.push_back(P(b,i));
		}
	}
	for(int i=0;i<K;i++){
		if(ass[i].first>ini[i]){
			int a=ass[i].first-ini[i];
			if(a>0){
				ad[i].push_back(P(a,ass[i].second));
			}
		}
	}
	for(int i=0;i<K;i++){
		sort(ad[i].begin(),ad[i].end());
		reverse(ad[i].begin(),ad[i].end());
	}
	for(int i=0;i<K;i++){
		long long cur=ini[i];
		for(int j=0;j<ad[i].size();j++){
			long long nxt=cur+ad[i][j].first;
			items.push_back(Item(Frac(nxt,cur),ad[i][j].second));
			cur=nxt;
		}
	}
	for(int i=0;i<mult.size();i++){
		items.push_back(Item(Frac(mult[i].first,1),mult[i].second));
	}
	if(items.size()<=M){
	//	printf("%d\n",items.size());
	//	for(int i=0;i<items.size();i++){
	//		printf("%d%c",items[i].second+1,i==items.size()?'\n':' ');
	//	}
		ans=items.size();
		for(int i=0;i<items.size();i++){
			need[items[i].second]=true;
		}
//		return 0;
	}
	sort(items.begin(),items.end());
	reverse(items.begin(),items.end());
//	for(int i=0;i<items.size();i++){
//		items[i].first.print();
//	}
	if(ans==-1) ans=M;
	for(int i=0;i<ans;i++){
		need[items[i].second]=true;
	}
/*	printf("%d\n",M);
	for(int i=0;i<M;i++){
		printf("%d%c",items[i].second+1,i==M-1?'\n':' ');
	}*/
	printf("%d\n",ans);
	int c=0;
	for(int i=0;i<N;i++){
		if(need[i]&&ts[i]==1){
			printf("%d%c",i+1,++c==ans?'\n':' ');
		}
	}
	for(int i=0;i<N;i++){
		if(need[i]&&ts[i]==2){
			printf("%d%c",i+1,++c==ans?'\n':' ');
		}
	}
	for(int i=0;i<N;i++){
		if(need[i]&&ts[i]==3){
			printf("%d%c",i+1,++c==ans?'\n':' ');
		}
	}
	return 0;
}