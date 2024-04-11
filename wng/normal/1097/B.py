n=int(raw_input())
poss=[[0]*360 for i in range(n+1)]
poss[0][0]=1
for i in range(n):
    k=int(raw_input())
    for j in range(360):
        if poss[i][j]:
            poss[i+1][(j+k)%360]+=poss[i][j]
            poss[i+1][(j-k)%360]+=poss[i][j]
if poss[n][0]:
    print "YES"
else:
    print "NO"