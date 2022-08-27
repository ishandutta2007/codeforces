#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int deg(int s){
	int d=0;
	int y=s;
	while(y%2==0){
		d++; y/=2;
	}
	return d;
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  int n,m;
  
  cin >> n>>m;
  //bool *b=new bool[(1+n)*(1+m)];
  std::vector<bool> b((1+n)*(1+m));
  //char *c=new char[(1+n)*(1+m)];
  std::vector<char> c((1+n)*(1+m));
  for(int i=0; i<(1+n)*(1+m); i++) b[i]=false;

  for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
          if(b[i*m+j]==false){
              std::vector<int> uc;
              if(j>1) uc.push_back(c[i*m+j-1]-'A');
              if(i>1) uc.push_back(c[(i-1)*m+j]-'A');
              if((j<m-1)&&(b[i*m+j+1])) uc.push_back(c[i*m+j+1]-'A');
              std::sort(uc.begin(), uc.end());
              char newc='A';
              int l=uc.size();
              if((l>0)&&(uc[0]==0)) {
                  newc='B';
                  if((l>1)&&((uc[1]==1)||((l>2)&&(uc[2]==1)))) {
                      newc='C';
                      if((l>2)&&(uc[2]==2)) newc='D';
                  }
              }
              int curi=i;
              int curj=j;
              while(1){
                  if(curi==n) break;
                  if(curj==m) break;
                  if(b[i*m+curj+1]==true) break;
                  if((j>0)&&(b[(curi+1)*m+j-1]==true)&&(c[(curi+1)*m+j-1]==newc)) break;
                  if((i>0)&&(c[(i-1)*m+curj+1]==newc)) break;
                  if((curj<(m-1))&&(b[i*m+curj+2])&&(c[i*m+curj+2]==newc)) break;
                  bool apos=true, bpos=true;
                  if((i>0)&&(c[(i-1)*m+curj+1]=='A')) apos=false;
                  if((i>0)&&(c[(i-1)*m+curj+1]=='B')) bpos=false;
                  if((curj<(m-1))&&(b[i*m+curj+2])&&(c[i*m+curj+2]=='A')) apos=false;
                  if((curj<(m-1))&&(b[i*m+curj+2])&&(c[i*m+curj+2]=='B')) bpos=false;
                  if(newc=='D') break;
                  if((newc>'A')&&(apos)) break;
                  if((newc>'B')&&(bpos)) break;
                  curi++;
                  curj++;
              }
              for(int p=i;p<=curi;p++)
                  for(int q=j;q<=curj;q++){
                      b[m*p+q]=true;
                      c[m*p+q]=newc;

                  }

          }

      }
  }

  for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++) cout<<c[i*m+j];
      cout<<endl;
  }

}