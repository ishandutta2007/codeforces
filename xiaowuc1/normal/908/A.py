s = raw_input()
ret = 0
for x in s:
    if x in "aeiou13579":
        ret += 1
print ret