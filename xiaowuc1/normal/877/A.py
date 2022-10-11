l = ["Danil", "Olya", "Slava", "Ann", "Nikita"]
s = raw_input()
ret = 0
for x in l:
  a = s.find(x)
  b = s.rfind(x)
  if a < 0 and b < 0:
    continue
  if a != b:
    ret += 2
  else:
    ret += 1
print "YES" if ret == 1 else "NO"