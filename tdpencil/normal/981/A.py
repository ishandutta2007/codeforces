
s=input()
x = 0
for i in range(len(s)):
    for j in range(i+1, len(s)):
        r = s[i:j+1]
        if r != r[::-1]:
            x = max(x, len(r))
print(x)