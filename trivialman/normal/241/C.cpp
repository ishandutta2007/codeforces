#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//#define N 200010// 
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define CL(x) memset(x,0,sizeof(x))

struct mir{
	double l,r;int v;
	bool operator<(mir right){return this->l<right.l;}
};

int n,upnum=0,downnum=0,ans=0;
double hl,hr;
mir up[200],down[200];

bool check(double pos,mir a[],int &score,int &ind,int num){
	for(int tmp=ind;ind<=num&&a[ind].l<=pos;++ind){
		if(ind>tmp&&a[ind].r>=pos){
			score+=a[ind].v;
			return true;
		}
	}
	return false;
}

int main(){
	cin>>hl>>hr>>n;hr=100-hr;
	up[0]=down[0]={0,0,0};
	rep(i,1,n){
		int v;double l,r;char ch;
		cin>>v>>ch>>l>>r;
		if(ch=='T')up[++upnum]={l,r,v};
		else down[++downnum]={l,r,v};
	}
	sort(up+1,up+upnum+1);
	sort(down+1,down+downnum+1);
	rep(i,1,n){
		hl=100-hl;
		double toth = hl+hr+100*(i-1);
		double slope = toth/1e5;
		int score=0,indu=0,indd=0;
		bool flag=true;
		rep(j,0,i-1){
			double pos=(hl+100*j)/slope;
			//cout<<pos<<endl;
			if(j%2==0){
				if(!check(pos,up,score,indu,upnum)){
					flag=false;//break;
				}
			}else{
				if(!check(pos,down,score,indd,downnum)){
					flag=false;//break;
				}
			}
		}
		if(flag&&score>ans)ans=score;
		//printf("up, times=%d, success=%d, score=%d\n",i,flag,score);
		
		hl=100-hl;hr=100-hr;
		toth = hl+hr+100*(i-1);
		slope = toth/1e5;
		score=indu=indd=0;flag=true;
		rep(j,0,i-1){
			double pos=(hl+100*j)/slope;
			//cout<<pos<<endl;
			if(j%2==0){
				if(!check(pos,down,score,indd,downnum)){
					flag=false;//break;
				}
			}else{
				if(!check(pos,up,score,indu,upnum)){
					flag=false;//break;
				}
			}
		}
		if(flag&&score>ans)ans=score;
		//printf("down, times=%d, success=%d, score=%d\n",i,flag,score);
	}
	cout<<ans<<endl;
	return 0;
}