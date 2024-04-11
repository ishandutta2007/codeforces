a = input().strip()
a = a.lower()
a = [i for i in a if not i in ['a','e','i','o','u','y']]
a = ''.join(['.'+i for i in a])
print(a)