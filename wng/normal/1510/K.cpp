#include <bits/stdc++.h>

using namespace std;

vector<int> op1(vector<int> v) {
    vector<int> res(v.size());
    for(int c=0;c<res.size();c++) {
        res[c]=v[c];
    }
    for(int c=0;c<res.size();c+=2) {
        swap(res[c],res[c+1]);
    }
    return res;
}

vector<int> op2(vector<int> v) {
    vector<int> res(v.size());
    for(int c=0;c<res.size();c++) {
        res[c]=v[c];
    }
    for(int c=0;c*2<res.size();c++) {
        swap(res[c],res[c+res.size()/2]);
    }
    return res;
}

bool sorted(vector<int> &v) {
    int N = v.size();
    bool valide = true;
     for(int c=0;c<N;c++) {
        if(c>0 && v[c-1]>v[c]) {
            valide = false;
        }
    }
    return valide;
}

int main()
{
    int N;
    cin>>N;
    N*=2;
    vector<int> v(N);
    for(int c=0;c<N;c++) {
        cin>>v[c];
    }

    if(sorted(v)) {
        cout<<0<<endl;
        return 0;
    }

    queue<tuple<int,int,vector<int> > > bfs;

    bfs.push(make_tuple(0,1,op1(v)));
    bfs.push(make_tuple(1,1,op2(v)));

    while(bfs.size()) {
        int op = get<0>(bfs.front());
        int d = get<1>(bfs.front());
        vector<int> p = get<2>(bfs.front());
        bfs.pop();

        if(sorted(p)) {
            cout<<d<<endl;
            return 0;
        }
        if(d < N) {
            vector<int> p2 = (op==0?op2(p):op1(p));
            bfs.push(make_tuple(!op,d+1,p2));
        }
    }

    cout<<-1;
}