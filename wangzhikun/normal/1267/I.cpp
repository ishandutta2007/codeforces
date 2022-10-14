#include <bits/stdc++.h>

using namespace std;

int T,n;

bool qued[220][210],qans[210][210];
int pred[10] = {0,1,2,3,4,5,6,7,8};
bool query(int a,int b){
    assert(a!=b);
    if(qued[a][b]){
        return qans[a][b];
    }
    qued[a][b] = 1;
    qued[b][a] = 1;
    cout<<"? "<<a<<' '<<b<<endl;
    cout.flush();
    char ch;
    /*if(pred[a]>pred[b])ch = '>';
    else ch = '<';
    cout<<"autoans "<<ch<<endl;
    */
    cin>>ch;
    if(ch == '>'){
        qans[a][b] = 1;
    }else{
        qans[a][b] = 0;
    }
    qans[b][a] = qans[a][b]^1;
    return qans[a][b];
}

int findm(vector<int> cv,int typ){
    for(auto ct:cv){
        int ok = 1;
        for(auto ct2:cv){
            if(ct == ct2)continue;
            if(query(ct,ct2)!=typ)ok = 0;
        }
        if(ok)return ct;
    }
    return -1;
}

int typ[210];

void solve3(){
    int a[3][2] = {1,2,3,4,5,6};
    if(!query(1,2))swap(a[0][0],a[0][1]);
    if(!query(3,4))swap(a[1][0],a[1][1]);
    if(!query(5,6))swap(a[2][0],a[2][1]);
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(!query(a[i][1],a[j][1])){
                swap(a[i][0],a[j][0]);
                swap(a[i][1],a[j][1]);
            }
        }
    }/*
    for(int i=0;i<3;i++){
        cout<<a[i][0]<<' '<<a[i][1]<<endl;
    }*/
    typ[a[0][0]] = 1;
    typ[a[1][1]] = typ[a[2][1]] = 0;
    int x = a[0][1],y = a[1][0],z = a[2][0];
    if(!query(y,z))swap(y,z);
    if(query(x,z)){
        typ[z] = 0;
        typ[x] = typ[y] = 1;
    }else{
        typ[z] = typ[y] = 1;
        typ[x] = 0;
    }
    //cout<<typ[1]<<' '<<typ[2]<<' '<<typ[3]<<' '<<typ[4]<<' '<<typ[5]<<' '<<typ[6]<<endl;
}

void add(int num){
    int x = num,y = num-1;
    int xj = 1,yj = 1;
    for(int i=1;i<=n*2;i++){
        if(typ[i] == 0 && !query(x,i))xj = 0;
        if(typ[i] == 0 && !query(y,i))yj = 0;
    }
    if(xj && yj){
        //cout<<233<<endl;
        vector<int> cg;
        for(int i=1;i<=n*2;i++)if(typ[i] == 1)cg.push_back(i);
        int mm = findm(cg,1);
        //cout<<mm<<endl;
        vector<int> cop;
        if(!query(x,y))swap(x,y);
        typ[x] = 1;
        for(int i=1;i<=n*2;i++)if(typ[i] == 1 && i!=mm && i!=x)cop.push_back(i);
        cop.push_back(y);
        int mi = findm(cop,0);
        typ[mi] = 0;
        for(auto ct:cop)if(ct!=mi)typ[ct] = 1;
    }
    if(xj && !yj){
        typ[x] = 1;
        typ[y] = 0;
    }
    if(yj && !xj){
        typ[y] = 1;
        typ[x] = 0;
    }
    if(!yj && !xj){
        vector<int> cv;
        for(int i=1;i<=n*2;i++)if(typ[i] == 0)cv.push_back(i);
        cv.push_back(x);
        cv.push_back(y);
        int cm = findm(cv,1);
        typ[cm] = 1;
        for(auto ct:cv)if(ct!=cm)typ[ct] = 0;
    }
}
int main(){
    cin>>T;
    while(T--){
        memset(qued,0,sizeof(qued));
        memset(qans,0,sizeof(qans));
        memset(typ,-1,sizeof(typ));
        
        cin>>n;
        solve3();
        for(int i=4;i<=n;i++){
            add(i*2);
        }
        cout<<"!\n";
        cout.flush();
    }
    return 0;
}