n,m = map(int,input().split())
a = list(map(int,input().split()))
b = [0]*(n+5)
c = [0]*(m+5)
c[0] = n
cur = 0
for i in range(m):
    c[b[a[i]]] -= 1
    b[a[i]] += 1
    c[b[a[i]]] += 1
    if c[cur] == 0:
        print(1,end='')
        cur += 1
    else:
        print(0,end='')