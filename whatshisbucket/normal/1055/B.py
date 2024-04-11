def main():
    n,m,l=map(int,input().split())
    a=list(map(int,input().split()))
    b=[1 if a[i]>l else 0 for i in range(n)]
    blocks=0
    ins=False
    for guy in b:
        if guy==1:
            if not ins:
                ins=True
                blocks+=1
        else:
            if ins:
                ins=False
    for i in range(m):
        c=input()
        if c[0]=="0":
            print(blocks)
        else:
            c=c.split()
            d,e=int(c[1]),int(c[2])
            f=b[d-1]
            if f==0:
                a[d-1]+=e
                if a[d-1]>l:
                    b[d-1]=1
                    if d==1:
                        if len(b)==1 or b[1]==0:
                            blocks+=1
                    elif d==n:
                        if b[-2]==0:
                            blocks+=1
                    else:
                        blocks+=1-[b[d-2],b[d]].count(1)
main()