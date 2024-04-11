<?php
$handle = fopen ("php://stdin","r");
$n = fgets(STDIN);
$a = trim(fgets(STDIN));
$ans = 1;
$z = 1;
$c = 0;
$pr = -1;
if($a[0] == '0')
{
    $z = 0;
}

for($i=2; $i<$n*2-1; $i=$i+2)
{
    if($a[$i]<>$a[$i-2])
    {
        if($pr<>$c)
        {
            if($pr!=-1)
            {
                $ans=0;
            }
            $pr=$c;
        }
        $c=0;
    }
    else 
    {
        $c++;
    }
}

if($pr<>$c)
{
    if($pr!=-1)
    {
        $ans=0;
    }
    $pr=$c;
}

if($ans==1)
{
    print ("YES");
}
else
{
    print ("NO");
}
fclose($handle);
?>