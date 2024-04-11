def main():
    n=int(input())
    a=list(map(int,input().split()))
    a.sort(reverse=True)
    mod=sum(a)%2
    counts=[0]*(n+1)
    for guy in a:
        counts[guy]+=1
    cumcounts=[0]*(n+1)
    cumcounts[0]=counts[0]
    for i in range(n):
        cumcounts[i+1]=cumcounts[i]+counts[i+1]
    partialsums=[0]*(n+1)
    curr=0
    for i in range(n):
        curr+=(i+1)*counts[i+1]
        partialsums[i+1]=curr
    partialsums.append(0)
    cumcounts.append(0)
    sumi=0
    diffs=[0]*n
    altdiffs=[0]*n
    for i in range(n):
        sumi+=a[i]
        rhs=i*(i+1)
        if a[i]>i:
            rhs+=partialsums[i]+(i+1)*(n-i-1-cumcounts[i])
        else:
            rhs+=partialsums[a[i]-1]+a[i]*(n-i-1-cumcounts[a[i]-1])
        diffs[i]=sumi-rhs
        
        rhs2=(i+1)*(i+2)
        if a[i]>i+1:
            rhs2+=partialsums[i+1]+(i+2)*(n-i-1-cumcounts[i+1])
        else:
            rhs2+=partialsums[a[i]-1]+a[i]*(n-i-1-cumcounts[a[i]-1])
        altdiffs[i]=sumi-rhs2
    mini=max(diffs)
    maxi=-max(altdiffs)
    mini=max(mini,0)
    maxi=min(maxi,n)
    out=""
    if mini%2!=mod:
        mini+=1
    if maxi%2==mod:
        maxi+=1
    for guy in range(mini,maxi,2):
        out+=str(guy)+" "
    if mini>maxi:
        print(-1)
    else:
        print(out)
main()