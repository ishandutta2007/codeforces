n=int(input())
a=list(map(int,input().split()))
seen=[0]*(n+3)
long=1
for guy in a:
    if guy**0.5>long-50:
        for i in range(long+1,1,-1):
            if guy%i==0:
                seen[i]+=seen[i-1]
                if i==long+1:
                    long+=1
    else:
        facs=[]
        bigfacs=[]
        for i in range(1,int(guy**0.5)+1):
            if guy%i==0:
                facs.append(i)
                bigfacs.append(guy//i)
        if facs[-1]==bigfacs[-1]:
            bigfacs.pop()
        facs+=bigfacs[::-1]
        for guy1 in facs[::-1]:
            if guy1<=long+1:
                seen[guy1]+=seen[guy1-1]
                if guy1==long+1:
                    long+=1          
    seen[1]+=1
print(sum(seen)%1000000007)