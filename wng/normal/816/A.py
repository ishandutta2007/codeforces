w=raw_input("")
h,m=[int(k) for k in w.split(":")]
T=h*60+m

def rev(n):
    return (n%10)*10+n/10
    
t=[]
for i in [0,1,2,3,4,5,10,11,12,13,14,15,20,21,22,23]:
    t+=[60*i+rev(i)]

ts=[(k-T)%(60*24) for k in t]


res=min(ts)
print (res)