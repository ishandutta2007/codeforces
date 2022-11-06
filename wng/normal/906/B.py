n,m=[int(k) for k in raw_input().split(" ")]

swap=False
if n>m:
    n,m=m,n
    swap=True

if m==1:
    print "YES"
    print 1
if m==2:
    print "NO"
if n<=2 and m==3:
    print "NO"
if m==3 and n==3:
    print "YES"
    print "6 1 8"
    print "7 5 3"
    print "2 9 4"
if m>=4:
    print "YES"
    #OK let's ta
    rb=[[(j,i) for i in range(m)] for j in range(n)]
    res=[[(j,i) for i in range(m)] for j in range(n)]
    rr=[[0 for i in range(m)] for j in range(n)]
    ms2=m/2
    if m%2==0:
        orderm=sorted(range(m),key=lambda x: (x%ms2 - (0.5 if x>=ms2 else 0)))
        orderm2=orderm[::-1]
    else:
        orderm=sorted(range(m/2)+range((m/2)+1,m),key=lambda x: ((x- (1 if x>=ms2 else 0))%ms2 + (0.5 if x>=ms2 else 0)))+[m/2]
        orderm2=[m/2]+sorted(range(m/2)+range((m/2)+1,m),key=lambda x: ((x- (1 if x>=ms2 else 0))%ms2 + (0.5 if x>=ms2 else 0)))
    ns2=(n+1)/2
    for i in range(n):
        for j in range(m):
                res[i][j]=rb[i][orderm[j]] if i%2==0 else rb[i][orderm2[j]]
    if not swap:
        for k in range(n):
            print " ".join([ str(i[0]*m+i[1]+1) for i in res[k]])
    else:    
        for k in range(m):
            print " ".join([str(i[1]*n+i[0]+1) for i in [res[j][k] for j in range(n)]])