s = input()
a = []
s = s.lower()
vow = "aeiouy"
for i in s:
    if i not in vow:
        a.append(i)
b = ["."+str(j) for j in a]
print("".join(b))