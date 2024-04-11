($n,$m)=split' ',<>;
$a=0;
while($n){
	if($n>=$m){
		$n-=$m-1;
		$a+=$m;
	}else{
		$a+=$n;
		$n=0;
	}
}
print "$a\n";