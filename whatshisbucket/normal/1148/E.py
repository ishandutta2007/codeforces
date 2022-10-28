n=int(input())
s=list(map(int,input().split()))
t=list(map(int,input().split()))
if sum(s)!=sum(t):
    print("NO")
else:
    s=[(s[i],i+1) for i in range(n)]
    s.sort()
    t.sort()
    diff=[0]*n
    for i in range(n):
        if s[i][0]==t[i]:
            diff[i]=0
        elif s[i][0]<t[i]:
            diff[i]=1
        else:
            diff[i]=-1
    move=[abs(s[i][0]-t[i]) for i in range(n)]
    sumi=sum(move)
    indu=0
    indd=0
    out=[]
    while sumi>0:
        if indd<indu:
            print("NO")
            exit()
        if diff[indu]==1 and move[indu]>0 and diff[indd]==-1 and move[indd]>0:
            a=min(move[indu],move[indd])
            move[indu]-=a
            move[indd]-=a
            out.append((s[indu][1],s[indd][1],a))
            sumi-=2*a
        elif diff[indu]==1 and move[indu]>0:
            indd+=1
        elif diff[indd]==-1 and move[indd]>0:
            indu+=1
        else:
            indd+=1
            indu+=1
    print("YES")
    print(len(out))
    for guy in out:
        print(guy[0],guy[1],guy[2])