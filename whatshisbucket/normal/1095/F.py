def main():
    n,m=map(int,raw_input().split())
    a=list(map(int,raw_input().split()))
    b=min(a)
    c=a.index(b)
    edges=[0]*(n+m)
    for i in xrange(n):
        edges[i]=(b+a[i],c,i)
    for i in xrange(m):
        x,y,z=map(int,raw_input().split())
        edges[-i-1]=(z,x-1,y-1)
    edges[c]=(3000000000000,0,0)
    edges.sort()
    edgess=0
    used=[]
    tree=[i for i in xrange(n+1)]
    def q(x):
        if x!=tree[x]:
            tree[x]=q(tree[x])
        return(tree[x])
    for w,u,v in edges:
        if edgess==n-1:
            break
        a,b=q(u),q(v)
        if a%2==1:
            a,b=b,a
        if a!=b:
            tree[a]=b
            used.append((u,v,w))
            edgess+=1
    print(sum(guy[2] for guy in used))
main()