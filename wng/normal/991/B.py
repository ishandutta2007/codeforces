n=int(raw_input())
a=[int(k) for k in raw_input().split(" ")]
#n=200
#a=[3]+[5]*199
t=[0]*6
sk=0
for k in a:
    t[k]+=1
    sk+=k

lim= (9*n)/2 if not n%2 else (9*n+1)/2
toget=lim-sk
res=0
if toget>0:
    for k in range(2,5):
        chopable=t[k]
        if t[k]*(5-k)>=toget:
            res+=(toget-1)/(5-k)+1
            break
        else:
            res+=chopable
            toget-=chopable*(5-k)

print res