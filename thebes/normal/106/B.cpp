#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int,int,int> wtf;
vector<wtf> vec;
int N, i, x, y, z, a;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++){
		scanf("%d%d%d%d",&x,&y,&z,&a);
		bool fnd = 0;
		for(int j=0;j<vec.size();j++){
			auto wts = vec[j];
			if(x>get<0>(wts)&&y>get<1>(wts)&&z>get<2>(wts)){
				vec.erase(vec.begin()+j);
				j--;
			}
			else if(x<get<0>(wts)&&y<get<1>(wts)&&z<get<2>(wts)) fnd=1;
		}
		if(!fnd) vec.push_back(make_tuple(x,y,z,a,i));
	}
	int ans = 1<<30, best = 0;
	for(int i=0;i<vec.size();i++)
		if(get<3>(vec[i])<ans)ans=get<3>(vec[i]),best=get<4>(vec[i]);
	printf("%d\n",best);
	return 0;
}