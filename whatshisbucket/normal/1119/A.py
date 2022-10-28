n=int(input())
c=list(map(int,input().split()))
start=c[0]
end=c[-1]
if start!=end:
    print(n-1)
else:
    i=0
    for guy in c:
        if guy!=start:
            break
        i+=1
    j=0
    for guy in c[::-1]:
        if guy!=end:
            break
        j+=1
    print(n-min(i+1,j+1))