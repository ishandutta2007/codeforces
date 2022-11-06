n,k=[int(k) for k in raw_input().split(" ")]
t=[None for i in range(n)]

th=[[0 for j in range(n)]for i in range(n)]
ph=[[0 for j in range(n)]for i in range(n)]
tv=[[0 for j in range(n)]for i in range(n)]
pv=[[0 for j in range(n)]for i in range(n)]

for i in range(n):
    t[i]=[ 1 if kk=="." else 0 for kk in raw_input()]
    for j in range(n):
        th[i][j]=(th[i][j-1]+1) if t[i][j] else 0
        if not th[i][j] and th[i][j-1]>=k:
            nn=th[i][j-1]
            for kk in range(1,nn+1):
                ph[i][j-kk]=max(1,min(min(k,nn+1-k),min(kk,nn+1-kk)))
    j=n
    if th[i][j-1]>=k:
        nn=th[i][j-1]
        for kk in range(1,nn+1):
            ph[i][j-kk]=max(1,min(min(k,nn+1-k),min(kk,nn+1-kk)))
        

for i in range(n):
    for j in range(n):
        tv[j][i]=(tv[j-1][i]+1) if t[j][i] else 0
        if not tv[j][i] and tv[j-1][i]>=k:
            nn=tv[j-1][i]
            for kk in range(1,nn+1):
                pv[j-kk][i]=max(1,min(min(k,nn+1-k),min(kk,nn+1-kk)))
    j=n
    if tv[j-1][i]>=k:
        nn=tv[j-1][i]
        for kk in range(1,nn+1):
            pv[j-kk][i]=max(1,min(min(k,nn+1-k),min(kk,nn+1-kk)))
                

tot=[[pv[i][j]+ph[i][j] for j in range(n)]for i in range(n)]


mx=max([max(row) for row in tot])

i=0
j=0
while tot[i][j]!=mx:
    j+=1
    if not j%n:
        j=0
        i+=1
print i+1,j+1