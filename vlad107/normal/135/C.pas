{$r-,q-,s-,i-,o+}
var
  tmp,p,s:ansistring;
  j,kt,k1,k,i:longint;
  t:array[0..50]of ansistring;
  
{
  function rec(s:string;x:longint):string;
    var
      p,ans:string;
      i:longint;
      
    begin
      if (length(s)=2)
        then begin
          rec:=s;
          exit;
        end;
      if (x=0)then ans:='11'else ans:='00';
      for i:=1 to length(s) do begin
        p:=s;
        delete(p,i,1);
        p:=rec(p,1-x);
        if (x=0)and(p<ans)then ans:=p else
        if (x=1)and(p>ans)then ans:=p;
      end;
      rec:=ans;
    end;
    
  function gready(s:string):string;
    var
      i:longint;
      
    begin
      while (length(s)>2)do begin
        i:=1;
        while (i<=length(s))and(s[i]<>'1')do inc(i);
        if (i>length(s))then i:=1;
        delete(s,i,1);
        if (length(s)=2)then break;
        i:=1;
        while (i<=length(s))and(s[i]<>'0')do inc(i);
        if (i>length(s))then i:=1;
        delete(s,i,1);
      end;
      gready:=s;
    end;
}    
  function gready2(s:ansistring):ansistring;
    var
      k,i,k0,k1:longint;
      
    begin
      k0:=0;k1:=0;
      for i:=1 to length(s)do
        if (s[i]='0')then inc(k0)else inc(k1);
      k:=(length(s)-1)div 2;
      if (k1<=k)then begin
        gready2:='00';
        exit;
      end;
      k:=k1-k;
      if (k>1)then begin
        gready2:='11';
        exit;
      end;
      if (s[length(s)]='1')
        then gready2:='01'
        else gready2:='10';
    end;

begin
  readln(s);
  kt:=0;
  p:=s;
  for i:=1 to length(s)do if (p[i]='?')then p[i]:='0';
  inc(kt);t[kt]:=gready2(p);
  p:=s;
  for i:=1 to length(s)do if (p[i]='?')then p[i]:='1';
  inc(kt);t[kt]:=gready2(p);
  k:=(length(s)-1)div 2;
  k1:=k+1;
  p:=s;
  for i:=1 to length(s)do if (p[i]='1')then dec(k1);
  for i:=1 to length(s)do 
    if (p[i]='?')then begin
      if (k1>0)then begin
        dec(k1);
        p[i]:='1';
      end else p[i]:='0';
    end;
  inc(kt);t[kt]:=gready2(p);
  k1:=k+1;
  p:=s;
  for i:=1 to length(s)do if (p[i]='1')then dec(k1);
  for i:=length(s) downto 1 do 
    if (p[i]='?')then begin
      if (k1>0)then begin
        dec(k1);
        p[i]:='1';
      end else p[i]:='0';
    end;
  inc(kt);t[kt]:=gready2(p);
  for i:=1 to kt-1 do 
    for j:=1 to kt-1 do 
      if (t[j]>t[j+1])then begin
        tmp:=t[j];t[j]:=t[j+1];t[j+1]:=tmp;
      end;
  t[0]:='~';
  for i:=1 to kt do 
    if (t[i]<>t[i-1])
      then writeln(t[i]);
end.