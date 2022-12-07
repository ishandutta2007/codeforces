import array
T=int(input())
for Tid in range(T):
    n,k=map(int,input().split())
    a=input()
    def c1():
        sum=0
        tmp=k
        for i in range(n):
            if a[i]=='W':
                sum+=2
            else:
                if tmp!=0:
                    tmp,sum=tmp-1,sum+2
        #print('ANS=%d' % sum)
        return sum
    def c2():
        sum,la=0,-(1<<30)
        b=[]
        for i in range(n):
            if a[i]=='W':
                if i==0 or a[i-1]=='L':
                    sum+=1
                if i!=0 and a[i-1]=='L' and la>0:
                    b.append(la)
                la=0
            else:
                la=la+1
        tmp=k
        b=sorted(b)
        #print(b,tmp)
        for i in range(len(b)):
            if tmp>=b[i]:
                tmp-=b[i]
                sum-=1
        return max(sum,1)
    print(max(c1()-c2(),0))