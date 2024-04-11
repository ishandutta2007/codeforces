#include <bits/stdc++.h>
using namespace std;

vector<int> x;
int graph[1000005];
vector<int> vt[1000005];
int mx[1000005];
int a, b, len;

int fw[1000005];
void update(int pos, int val)
{
    for (pos = max(1, len - pos); pos <= len; pos += pos & -pos)
        if (fw[pos] > val) fw[pos] = val;
}
int query(int pos)
{
    int ret = INT_MAX;
    for (pos = len - pos; pos; pos -= pos & -pos)
        if (ret > fw[pos]) ret = fw[pos];
    return ret;
}

namespace fio {
    const int BSIZE = 524288;
    char buffer[BSIZE];
    int p = BSIZE;
    inline char readChar() {
        if(p == BSIZE) {
            fread(buffer, 1, BSIZE, stdin);
            p = 0;
        }
        return buffer[p++];
    }
    int readInt() {
        char c = readChar();
        while ((c < '0' || c > '9') && c != '-') {
            c = readChar();
        }
        int ret = 0; bool neg = c == '-';
        if (neg) c = readChar();
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + c - '0';
            c = readChar();
        }
        return neg ? -ret : ret;
    }
} 

int main()
{
    int n;
    n = 100000;
    n = fio::readInt();
    for (int i = 1; i <= n; i++)
    {
        int t;
        t = i;
        t = fio::readInt();
        if (t >= 3) x.push_back(t);
    }
    sort(x.begin(), x.end(), greater<>());
    x.erase(unique(x.begin(), x.end()), x.end());
    b = 1000000000; a = b - 1000000;
    b = fio::readInt();
    a = fio::readInt();
    len = b - a + 1;

    for (int t : x)
    {
        for (int p = (a + t - 1) / t * t; p < b - 1; p += t)
        {
            if (mx[p - a] < t) mx[p - a] = t;
        }
    }
    fill(fw + 1, fw + len + 1, INT_MAX);
    update(0, 0);

    for (int i = 0; i < len - 1; i++)
    {
        int v = query(i);
        if (mx[i]) update(i + mx[i] - 1, v + 1);
        else update(i + 1, v + 1);
    }

    printf("%d\n", query(len - 1));
    fflush(stdout);
    _Exit(0);
}