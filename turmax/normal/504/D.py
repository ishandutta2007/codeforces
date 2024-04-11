def main():
    n=int(input())
    a=[]
    b=[]
    for i in range(n):
        x=int(input())
        #print(x," x ")
        good=False
        mask=(2**i)
        for i2 in range(len(b)):
            o=b[i2][0]^x
            #print(x,o)
            if(o<x):
                mask=(mask^b[i2][1])
                x=o
        #print(mask)
        if(x!=0):
            for i in range(len(b)):
                h=b[i][0]^x
                if(h<b[i][0]):
                    b[i][0]=h
                    b[i][1]^=mask
            b.append([x,mask])
            #for z in b:
            #    print(z[0],z[2])
            print(0)
        else:
            v=[]
            #print(mask,i)
            o=1
            for j in range(i):
                if((mask & o)!=0):
                    v.append(j)
                o*=2
            print(len(v),end=' ')
            for u in v:
                print(u,end=' ')
            print()
main()