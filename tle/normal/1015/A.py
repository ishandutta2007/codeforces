n,m=map(int,raw_input().split(' '))
g=[]
ts=[]
for w in range(0,n):
    l,r=map(int,raw_input().split(' '))
    g.append(range(l,r+1))
for w in range(1,m+1):
    i=False
    for p in g:
        if w in p:
            i=True
    if i==False:
        ts.append(w)
print(len(ts))
print(' '.join(map(str,ts)))