#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Line {
    long long A,B,C;
    bool has(pair<double,double> x) {
        return fabs(A*x.first+B*x.second-C)<=1e-9;
    }
    pair<double,double> inter(Line b) {
        pair<double,double> res;
        res.first = 1.*(C*b.B-B*b.C)/(A*b.B-B*b.A);
        res.second = 1.*(C*b.A-A*b.C)/(B*b.A-A*b.B);
        return res;
    }
};

int n;
Line lines[100013];
vector<pair<int,int> > ans;
vector<int> left;
vector<int> left2;
vector<int> reset;

const int need[6] = {0,1,80,180,320,500};

void solve(int k) {
    if (k==0) return;
    if (left.size()==0) return;
    if (left.size()==1) {
        ans.push_back(make_pair(left[0],-1));
        left.pop_back();
        return;
    }
    if (left.size()<=k) {
        ans.push_back(make_pair(left.back(),-1));
        left.pop_back();
        solve(k-1);
        return;
    }
    for (int r=0;r<need[k];r++) {
        int a,b;
        do {
            a = left[rand()%left.size()];
            b = left[rand()%left.size()];
        } while (a==b);
        if (lines[a].A*lines[b].B==lines[a].B*lines[b].A) continue;
        pair<double,double> x = lines[a].inter(lines[b]);
        int cnt = 0;
        for (int i: left) {
            if (lines[i].has(x)) cnt+=1;
        }
        if (cnt>k || cnt>=(left.size()+k-1)/k) {
            for (int i: left) {
                if (!lines[i].has(x)) left2.push_back(i);
            }
            swap(left,left2);
            left2.clear();
            ans.push_back(make_pair(a,b));
            solve(k-1);
            break;
        }
    }
}

int main() {
    int k;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        lines[i] = {a,b,c};
        reset.push_back(i);
    }
    for (int T=0;T<10;T++) {
		left = reset;
		solve(k);
		if (left.size()==0) {
			printf("YES\n");
			printf("%d\n",ans.size());
			for (pair<int,int> i: ans) printf("%d %d\n",i.first,i.second);
			return 0;
		}
		ans.clear();
    }
    printf("NO\n");

    return 0;
}