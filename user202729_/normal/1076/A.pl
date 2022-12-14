$n=<>;
$s=<>;
$i=0;
++$i while substr($s,$i,1) le substr($s,$i+1,1);
substr($s,$i,1)='';
print $s;