vowels = "aeiouy"
n = int(raw_input())
s = raw_input()
ret = ""
for x in s:
  if len(ret) == 0 or ret[-1] not in vowels or x not in vowels:
    ret += x
print ret