gets;a=gets.split.map(&:to_i).sort
p a.each_with_index.map{|x,i|x*(i+2)}.inject(:+)-a[-1]