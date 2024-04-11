{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const md = round(1e9+9);
      let: string = 'ACGT';
var
  ans,ii,jj,kk,max,km,nn,m,n,i,j,t,q,k: longint;
  dd: boolean;
  sw,s: array [0..110] of string;
  ss,st: string;
  a: array [0..110,'A'..'Z'] of longint;
  fn: array [0..110,0..110] of longint;
  maxw,pv,de,len: array [0..110] of longint;
  pc: array [0..110] of char;
  f: array [0..1010,0..110,0..11] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(nn,m);
  fillchar(a,sizeof(a),0);
  fillchar(maxw,sizeof(maxw),0);
  n:=1;
  de[1]:=0;
  for i:=1 to m do
  begin
    readln(s[i]);
    len[i]:=length(s[i]);
    t:=1;
    for j:=1 to len[i] do
    begin
      if a[t,s[i,j]] = 0 then
      begin
        inc(n);
        pv[n]:=t;
        pc[n]:=s[i,j];
        de[n]:=de[t]+1;
        a[t,s[i,j]]:=n;
      end;
      t:=a[t,s[i,j]];
    end;
    maxw[t]:=len[i];
  end;
  sw[1]:='';
  for i:=2 to n do sw[i]:=sw[pv[i]]+pc[i];
  dd:=True;
  while dd do
  begin
    dd:=False;
    for i:=1 to n do
      if maxw[i] > 0 then
        for j:=1 to n do
          if length(sw[j]) > length(sw[i]) then
            if Copy(sw[j],length(sw[j])-length(sw[i])+1,length(sw[i])) = sw[i] then
              if maxw[i] > maxw[j] then
              begin
                maxw[j]:=maxw[i];
                dd:=True;
              end;
  end;
  for i:=1 to n do
    for q:=1 to 4 do
    begin
      st:='';
      t:=i;
      while t > 1 do
      begin
        st:=pc[t]+st;
        t:=pv[t];
      end;
      st:=st+let[q];
      max:=0; km:=1;
      for ii:=2 to n do
      begin
        ss:=''; t:=ii;
        while t > 1 do
        begin
          ss:=pc[t]+ss;
          t:=pv[t];
        end;
        if length(ss) > length(st) then continue;
        if Copy(st,length(st)-length(ss)+1,length(ss)) = ss then
          if length(ss) > max then
          begin
            max:=length(ss);
            km:=ii;
          end;
      end;
      fn[i,q]:=km;
    end;
  fillchar(f,sizeof(f),0);
  f[0,1,0]:=1;
  for i:=0 to nn-1 do
    for j:=1 to n do
      for k:=0 to de[j] do
        if f[i,j,k] > 0 then
          for q:=1 to 4 do
          begin
            ii:=i+1;
            jj:=fn[j,q];
            kk:=k+1;
            if maxw[jj] >= k+1 then kk:=0;
            inc(f[ii,jj,kk],f[i,j,k]);
            if f[ii,jj,kk] >= md then dec(f[ii,jj,kk],md);
          end;
  ans:=0;
  for i:=1 to n do ans:=(ans+f[nn,i,0]) mod md;
  writeln(ans);
  close(input);
  close(output);
end.