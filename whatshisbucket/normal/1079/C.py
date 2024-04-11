n=int(input())
a=list(map(int,input().split()))
if n==1:
    print(1)
    exit()
diffs=[0]*(n-1)
for i in range(n-1):
    if a[i+1]>a[i]:
        diffs[i]=1
    elif a[i+1]==a[i]:
        diffs[i]=0
    else:
        diffs[i]=-1
fingers=[0]*n
runs=[0]*(n-1)
runs[-1]=diffs[-1]
for i in range(n-3,-1,-1):
    if diffs[i]==0:
        runs[i]=0
    elif diffs[i]>0:
        runs[i]=max(1,runs[i+1]+1)
    else:
        runs[i]=min(-1,runs[i+1]-1)
if max(runs)>4 or min(runs)<-4:
    print(-1)
else:
    good=True
    for i in range(n-6):
        if abs(runs[i])==4 and runs[i]==-runs[i+5]:
            good=False
            break
    if not good:
        print(-1)
    else:
        curr=0
        for i in range(n-1):
            if curr==0:
                if runs[i]>0:
                    fingers[i]=1 if fingers[i-1]!=1 else 2
                    curr=1
                elif runs[i]<0:
                    fingers[i]=5 if fingers[i-1]!=5 else 4
                    curr=-1
            elif curr==1:
                if runs[i]>0:
                    fingers[i]=fingers[i-1]+1
                elif runs[i]<0:
                    fingers[i]=5
                    curr=-1
                else:
                    fingers[i]=fingers[i-1]+1
                    curr=0
            else:
                if runs[i]>0:
                    fingers[i]=1
                    curr=1
                elif runs[i]<0:
                    fingers[i]=fingers[i-1]-1
                else:
                    fingers[i]=fingers[i-1]-1
                    curr=0
        if curr!=0:
            fingers[-1]=fingers[-2]+curr
        else:
            fingers[-1]=(fingers[-2]+1)%5+1
        if fingers[0]==0:
            fingers[0]=(fingers[1]+1)%5+1
        for i in range(1,n-1):
            if fingers[i]==0:
                if fingers[i-1]==fingers[i+1]:
                    fingers[i]=(fingers[i-1]+1)%5+1
                elif fingers[i-1]==5 and fingers[i+1]==0:
                    fingers[i]=4
                else:
                    k=fingers[i-1]+fingers[i+1]
                    if k%2==0:
                        fingers[i]=k//2
                    else:
                        new=((k+5)//2)%5
                        if new==0:
                            new=5
                        fingers[i]=new
#        for i in range(n-1):
#            if fingers[i]==fingers[i+1]:
#                print(a[i-10:i+10],fingers[i-10:i+10])
        fingers=[str(guy) for guy in fingers]
        print(" ".join(fingers))