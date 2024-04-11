n=int(input())
times={}
names={}
for k in range(n):
    s=input()
    subs=[]
    a=len(s)
    for i in range(a):
        for j in range(i+1,a+1):
            subs.append(s[i:j])
    for word in set(subs):
        if word in times:
            times[word]+=1
        else:
            names[word]=s
            times[word]=1
q=int(input())
for i in range(q):
    t=input()
    if t in times:
        print(times[t],names[t])
    else:
        print(0,"-")