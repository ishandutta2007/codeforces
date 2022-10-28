n=int(input())
a=input()
counts=[]
alphabet="abcdefghijklmnopqrstuvwxyz"
for char in alphabet:
    counts.append(a.count(char))
out=""
for i in range(26):
    out+=alphabet[i]*counts[i]
print(out)