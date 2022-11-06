n,m=[int(k) for k in raw_input().split(" ")]
g=[[-1]*(m+2)]
for i in range(n):
    g+=[[-1]+[-2 if k=="*" else (int(k) if k!="." else 0) for k in raw_input()]+[-1]]

g+=[[-1]*(m+2)]

isok=True
for i in range(1,n+1):
    for j in range(1,m+1):
        if g[i][j]>=0:
            ss=0
            for k in range(-1,2):
                for kk in range(-1,2):
                    if k or kk:
                        if g[i+k][j+kk]==-2:
                            ss+=1
            if ss!=g[i][j]:
                isok=False

if isok:
    print "YES"
else:
    print "NO"