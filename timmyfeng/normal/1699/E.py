import sys

input_nums = [int(i) for i in sys.stdin.read().split()]
input_it = 0

def read_int():
 global input_it
 input_it += 1
 return input_nums[input_it - 1]

output_nums = []

def print_int(x):
 global output_nums
 output_nums.append(str(x))

t = read_int()
for _ in xrange(t):
 n = read_int()
 m = read_int()
 
 a = [False] * (m + 1)
 for i in xrange(n):
  a[read_int()] = True
 
 # INF := m + 1
 count_max = [0] * (m + 2)
 count_max[m + 1] = a.count(True)
 cur_max = m + 1
 
 answer = m + 1
 max_factor = [m + 1] * (m + 1)
 
 for i in xrange(m, 0, -1):
  if a[i]:
   count_max[max_factor[i]] -= 1
   count_max[i] += 1
  max_factor[i] = i
  
  for j in xrange(i, m // i + 1):
   x = i * j
   if a[x]:
    count_max[max_factor[x]] -= 1
   max_factor[x] = min(max_factor[j], max_factor[x])
   if a[x]:
    count_max[max_factor[x]] += 1
   
  while count_max[cur_max] == 0:
   cur_max -= 1
  
  if cur_max <= m:
   answer = min(answer, cur_max - i)
 
 print_int(answer)

print '\n'.join(output_nums)