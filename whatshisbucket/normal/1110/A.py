b,k=map(int,input().split())
a=list(map(int,input().split()))
if b%2==0:
    if a[-1]%2==0:
        print("even")
    else:
        print("odd")
else:
    tot=0
    for guy in a:
        if guy%2==1:
            tot+=1
    if tot%2==0:
        print("even")
    else:
        print("odd")