s,k=input(),int(input())
l=len(s)//k
u=[s[i::l] for i in range(l)]
print(["NO","YES"][u==u[::-1] and l*k==len(s)])