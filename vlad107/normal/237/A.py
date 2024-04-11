n=int(input())
t=[0]*9999
for i in map(lambda x:x[0]*60+x[1],[map(int,raw_input().split()) for _ in range(n)]):t[i]+=1
print max(t)