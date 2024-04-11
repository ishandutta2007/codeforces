R=lambda:map(int,raw_input().split())
n,m,d=R()
a=[]
for i in range(n):a+=R()
i=sorted(a)[n*m/2]
print [sum([abs(x-i) for x in a])/d,-1][len(set(map(lambda x:x%d,a)))!=1]