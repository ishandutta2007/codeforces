s = input()
val = eval(s)
for i in range(len(s)):
    if s[i] == '+':
        c = -5
        j = i+1
        while j < len(s) and s[j] != '+' and s[j] != '-':
            j += 1
            c *= 10
        val += c
    if s[i] == '-':
        c = 3
        j = i+1
        while j < len(s) and s[j] != '+' and s[j] != '-':
            j += 1
            c *= 10
        val += c
print(val)