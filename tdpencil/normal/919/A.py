a,b=map(int,input().split());c=[]
for _ in " "*a:e,d=map(int,input().split());c+=[(b/d)*e]
print(min(c))