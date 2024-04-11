n,m=map(int,input().split())
before=[None]+[-1]*n
after=[None]+[-1]*n
for i in range(m):
    l=list(map(int,input().split()))
    before[l[0]]=False
    after[l[-1]]=False
    for i in range(n-1):
        if after[l[i]]==-1:
            after[l[i]]=l[i+1]
        elif after[l[i]]!=l[i+1]:
            after[l[i]]=False
        if before[l[i+1]]==-1:
            before[l[i+1]]=l[i]
        elif before[l[i+1]]!=l[i]:
            before[l[i+1]]=False
seen=[None]+[0]*n
tot=0
for i in range(1,n+1):
    if seen[i]==0:
        start=i
        end=i
        leng=1
        seen[i]=1
        while True:
            if type(after[end])==int:
                leng+=1
                end=after[end]
                seen[end]=1
            else:
                break
        while True:
            if type(before[start])==int:
                leng+=1
                start=before[start]
                seen[start]=1
            else:
                break
        tot+=(leng*(leng+1))//2
print(tot)