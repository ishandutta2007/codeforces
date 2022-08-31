s = input()
a = []
for i in s:
      if i not in a:
            a.append(i)
b = len(a)
if b%2 == 0:
      print ( "CHAT WITH HER!")
else:
      print( "IGNORE HIM!")