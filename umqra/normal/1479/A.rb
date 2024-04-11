$stdout.sync = true

def query(x)
  puts "? #{x}"
  gets.chomp.to_i
end

def solution(n)
  value = yield(1)
  l, r = 1, value + 1
  while r - l > 1 do
    mid = (l + r) / 2
    a, b = yield(mid - 1), yield(mid)
    delta = mid - l
    if a < b
      r = mid
    elsif b <= value - delta 
      l, value = mid, b
    else
      r = mid
    end
  end
  return l
end

def stress
  array = (20).times.map { |x| x + 1 }.shuffle
  index = solution(array.length) { |x| array[x - 1] } - 1
  puts(array.inspect)
  puts(index)
  if not ((index == 0 or array[index - 1] > array[index]) and (index == array.length - 1 or array[index + 1] > array[index]))
    puts("Fail!")
  end
end

def main
  n = gets.chomp.to_i
  puts("! #{solution(n) { |x| query(x) }}")
end

main