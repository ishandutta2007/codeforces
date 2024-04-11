t=int(input())
for u in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    guys=[0,0,0]
    for guy in a:
        guys[guy%3]+=1
    tot=guys[0]
    a=min(guys[1],guys[2])
    guys[1]-=a
    guys[2]-=a
    tot+=a
    tot+=guys[1]//3
    tot+=guys[2]//3
    print(tot)