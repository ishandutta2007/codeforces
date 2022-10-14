a=input()
b= a.split(" ")[0]
c = a.split(" ")[1]
d = int(min(int(b),int(c)))
ans = 1
for i in range(1,d+1):
    ans*=i
print(ans)