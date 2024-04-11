__asm__(R"(	.file	"tmp4.cpp"
	.text
	.p2align 4,,15
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB3734:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB19:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	movq	%rdx, 72(%rsp)
	leaq	72(%rsp), %rdx
	movq	%r8, 80(%rsp)
	movq	%r9, 88(%rsp)
	movq	%rdx, 40(%rsp)
	call	__mingw_vprintf
	addq	$56, %rsp
	ret
	.seh_endproc
	.text
	.p2align 4,,15
	.globl	_Z7readstrPc
	.def	_Z7readstrPc;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7readstrPc
_Z7readstrPc:
.LFB3698:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movq	p1(%rip), %rax
	cmpq	p2(%rip), %rax
	movq	%rcx, %rbx
	je	.L17
.L4:
	leaq	1(%rax), %rdx
	movq	%rdx, p1(%rip)
	movzbl	(%rax), %eax
.L5:
	leaq	rbuf(%rip), %rsi
	jmp	.L6
	.p2align 4,,10
.L9:
	movq	p1(%rip), %rdx
	cmpq	p2(%rip), %rdx
	je	.L18
.L7:
	leaq	1(%rdx), %rax
	movq	%rax, p1(%rip)
	movzbl	(%rdx), %eax
.L6:
	leal	-33(%rax), %edx
	cmpb	$93, %dl
	ja	.L9
	leaq	rbuf(%rip), %rsi
	.p2align 4,,10
.L12:
	movb	%al, (%rbx)
	addq	$1, %rbx
	movq	p1(%rip), %rdx
	cmpq	p2(%rip), %rdx
	je	.L19
.L10:
	leaq	1(%rdx), %rax
	movq	%rax, p1(%rip)
	movzbl	(%rdx), %eax
	leal	-33(%rax), %edx
	cmpb	$93, %dl
	jbe	.L12
.L11:
	movb	$0, (%rbx)
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
.L19:
	leaq	rbuf(%rip), %rax
	movq	%rax, p1(%rip)
	call	*__imp___iob_func(%rip)
	leaq	rbuf(%rip), %rcx
	movl	$1, %edx
	movq	%rax, %r9
	movl	$8388608, %r8d
	call	fread
	movq	p1(%rip), %rdx
	addq	%rsi, %rax
	movq	%rax, p2(%rip)
	cmpq	%rdx, %rax
	jne	.L10
	jmp	.L11
	.p2align 4,,10
.L18:
	leaq	rbuf(%rip), %rax
	movq	%rax, p1(%rip)
	call	*__imp___iob_func(%rip)
	leaq	rbuf(%rip), %rcx
	movl	$1, %edx
	movq	%rax, %r9
	movl	$8388608, %r8d
	call	fread
	movq	p1(%rip), %rdx
	addq	%rsi, %rax
	movq	%rax, p2(%rip)
	cmpq	%rdx, %rax
	jne	.L7
	movl	$-1, %eax
	jmp	.L6
	.p2align 4,,10
.L17:
	leaq	rbuf(%rip), %rsi
	movq	%rsi, p1(%rip)
	call	*__imp___iob_func(%rip)
	movq	%rsi, %rcx
	movq	%rax, %r9
	movl	$8388608, %r8d
	movl	$1, %edx
	call	fread
	addq	%rax, %rsi
	movq	p1(%rip), %rax
	movq	%rsi, p2(%rip)
	cmpq	%rax, %rsi
	jne	.L4
	movl	$-1, %eax
	jmp	.L5
	.seh_endproc
	.p2align 4,,15
	.globl	_Z8printstrSs
	.def	_Z8printstrSs;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8printstrSs
_Z8printstrSs:
.LFB3699:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movq	(%rcx), %rax
	xorl	%ebx, %ebx
	movq	%rcx, %rsi
	cmpq	$0, -24(%rax)
	je	.L20
	.p2align 4,,10
.L25:
	movl	-8(%rax), %edx
	testl	%edx, %edx
	js	.L22
	movq	%rsi, %rcx
	call	_ZNSs12_M_leak_hardEv
	movq	(%rsi), %rax
.L22:
	movzbl	(%rax,%rbx), %edx
	movq	p3(%rip), %rax
	addq	$1, %rbx
	leaq	1(%rax), %rcx
	movq	%rcx, p3(%rip)
	movb	%dl, (%rax)
	movq	(%rsi), %rax
	cmpq	%rbx, -24(%rax)
	ja	.L25
.L20:
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z8printstrPc
	.def	_Z8printstrPc;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8printstrPc
_Z8printstrPc:
.LFB3700:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, %rbx
	call	strlen
	xorl	%edx, %edx
	testl	%eax, %eax
	movl	%eax, %ecx
	jle	.L27
	.p2align 4,,10
.L31:
	movq	p3(%rip), %rax
	movzbl	(%rbx,%rdx), %r8d
	addq	$1, %rdx
	cmpl	%edx, %ecx
	leaq	1(%rax), %r9
	movq	%r9, p3(%rip)
	movb	%r8b, (%rax)
	jg	.L31
.L27:
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z11print_finalv
	.def	_Z11print_finalv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z11print_finalv
_Z11print_finalv:
.LFB3701:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	*__imp___iob_func(%rip)
	movq	p3(%rip), %r8
	leaq	wbuf(%rip), %rcx
	leaq	48(%rax), %r9
	movl	$1, %edx
	subq	%rcx, %r8
	addq	$40, %rsp
	jmp	fwrite
	.seh_endproc
	.section	.text$_Z4readIiEvRT_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_Z4readIiEvRT_
	.def	_Z4readIiEvRT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4readIiEvRT_
_Z4readIiEvRT_:
.LFB3720:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	p2(%rip), %rax
	movq	%rcx, %rbx
	movl	$0, (%rcx)
	movq	p1(%rip), %rcx
	cmpq	%rax, %rcx
	je	.L50
.L35:
	leaq	1(%rcx), %rdx
	movq	%rdx, p1(%rip)
	movzbl	(%rcx), %r9d
.L36:
	xorl	%esi, %esi
	leaq	rbuf(%rip), %rdi
	jmp	.L37
	.p2align 4,,10
.L40:
	xorl	%ecx, %ecx
	cmpb	$45, %r9b
	sete	%cl
	orl	%ecx, %esi
	cmpq	%rax, %rdx
	je	.L51
.L38:
	leaq	1(%rdx), %r8
	movq	%r8, p1(%rip)
	movzbl	(%rdx), %r9d
	movq	%r8, %rdx
.L37:
	movsbl	%r9b, %r8d
	leal	-48(%r8), %ecx
	cmpl	$9, %ecx
	ja	.L40
	leaq	rbuf(%rip), %rdi
	jmp	.L43
	.p2align 4,,10
.L53:
	movq	%rax, %rdx
	movq	p2(%rip), %rax
.L43:
	movl	(%rbx), %r9d
	cmpq	%rax, %rdx
	leal	(%r9,%r9), %ecx
	leal	(%rcx,%r9,8), %ecx
	leal	-48(%rcx,%r8), %ecx
	movl	%ecx, (%rbx)
	je	.L52
.L41:
	leaq	1(%rdx), %rax
	movq	%rax, p1(%rip)
	movsbl	(%rdx), %r8d
	leal	-48(%r8), %edx
	cmpl	$9, %edx
	jbe	.L53
.L42:
	testl	%esi, %esi
	je	.L34
	negl	(%rbx)
.L34:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.p2align 4,,10
.L52:
	leaq	rbuf(%rip), %rax
	movq	%rax, p1(%rip)
	call	*__imp___iob_func(%rip)
	leaq	rbuf(%rip), %rcx
	movl	$1, %edx
	movq	%rax, %r9
	movl	$8388608, %r8d
	call	fread
	movq	p1(%rip), %rdx
	addq	%rdi, %rax
	movq	%rax, p2(%rip)
	cmpq	%rdx, %rax
	jne	.L41
	jmp	.L42
	.p2align 4,,10
.L51:
	leaq	rbuf(%rip), %rax
	movq	%rax, p1(%rip)
	call	*__imp___iob_func(%rip)
	leaq	rbuf(%rip), %rcx
	movl	$1, %edx
	movq	%rax, %r9
	movl	$8388608, %r8d
	call	fread
	movq	p1(%rip), %rdx
	addq	%rdi, %rax
	movq	%rax, p2(%rip)
	cmpq	%rdx, %rax
	jne	.L38
	movl	$-1, %r9d
	jmp	.L37
	.p2align 4,,10
.L50:
	leaq	rbuf(%rip), %rsi
	movq	%rsi, p1(%rip)
	call	*__imp___iob_func(%rip)
	movq	%rsi, %rcx
	movq	%rax, %r9
	movl	$8388608, %r8d
	movl	$1, %edx
	call	fread
	movq	p1(%rip), %rcx
	addq	%rsi, %rax
	movq	%rax, p2(%rip)
	cmpq	%rcx, %rax
	jne	.L35
	movq	%rax, %rdx
	movl	$-1, %r9d
	jmp	.L36
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "tmp4.cpp\0"
.LC1:
	.ascii "T.getcnt()<=t\0"
.LC2:
	.ascii "%d\12\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB3707:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	movl	$4276744, %eax
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	call	___chkstk_ms
	subq	%rax, %rsp
	.seh_stackalloc	4276744
	.seh_endprologue
	xorl	%esi, %esi
	call	__main
	leaq	k(%rip), %rcx
	call	_Z4readIiEvRT_
	movl	k(%rip), %ecx
	movl	$1, %eax
	sall	%cl, %eax
	testl	%eax, %eax
	jle	.L56
	movq	__imp___iob_func(%rip), %rax
	movq	%rax, 40(%rsp)
	movq	%rax, %r15
.L107:
	movl	$1, %eax
	xorl	%edi, %edi
	leaq	A(%rip), %r14
	sall	%cl, %eax
	movslq	%esi, %rdx
	testl	%eax, %eax
	jle	.L69
	movq	%rdx, %rax
	leaq	rbuf(%rip), %rbp
	salq	$7, %rax
	addq	%rdx, %rax
	leaq	(%rdx,%rax,4), %r12
.L108:
	movslq	%edi, %rbx
	movq	p2(%rip), %rdx
	leaq	(%r12,%rbx), %rax
	movq	$0, (%r14,%rax,8)
	movq	p1(%rip), %rax
	cmpq	%rdx, %rax
	je	.L130
.L57:
	leaq	1(%rax), %rcx
	movq	%rcx, p1(%rip)
	movzbl	(%rax), %r8d
	movq	%rcx, %rax
.L58:
	xorl	%r13d, %r13d
	jmp	.L59
	.p2align 4,,10
.L62:
	xorl	%ecx, %ecx
	cmpb	$45, %r8b
	sete	%cl
	orq	%rcx, %r13
	cmpq	%rdx, %rax
	je	.L131
.L60:
	leaq	1(%rax), %rcx
	movq	%rcx, p1(%rip)
	movzbl	(%rax), %r8d
	movq	%rcx, %rax
.L59:
	movsbl	%r8b, %ecx
	leal	-48(%rcx), %r9d
	cmpl	$9, %r9d
	ja	.L62
	leaq	(%r12,%rbx), %r10
	jmp	.L65
	.p2align 4,,10
.L63:
	leaq	1(%rax), %rdx
	movq	%rdx, p1(%rip)
	movsbl	(%rax), %ecx
	leal	-48(%rcx), %eax
	cmpl	$9, %eax
	ja	.L64
	movq	%rdx, %rax
	movq	p2(%rip), %rdx
.L65:
	movq	(%r14,%r10,8), %r8
	subl	$48, %ecx
	movslq	%ecx, %rcx
	leaq	(%r8,%r8), %r9
	leaq	(%r9,%r8,8), %r8
	addq	%r8, %rcx
	cmpq	%rdx, %rax
	movq	%rcx, (%r14,%r10,8)
	jne	.L63
	leaq	rbuf(%rip), %rax
	movq	%r10, 48(%rsp)
	movq	%rax, p1(%rip)
	call	*%r15
	leaq	rbuf(%rip), %rcx
	movl	$1, %edx
	movq	%rax, %r9
	movl	$8388608, %r8d
	call	fread
	leaq	(%rax,%rbp), %rdx
	movq	p1(%rip), %rax
	movq	48(%rsp), %r10
	movq	%rdx, p2(%rip)
	cmpq	%rax, %rdx
	jne	.L63
.L64:
	testq	%r13, %r13
	je	.L66
	addq	%r12, %rbx
	negq	(%r14,%rbx,8)
.L66:
	movl	k(%rip), %ecx
	movl	$1, %eax
	addl	$1, %edi
	sall	%cl, %eax
	cmpl	%edi, %eax
	jg	.L108
.L69:
	addl	$1, %esi
	cmpl	%eax, %esi
	jl	.L107
.L56:
	leaq	t(%rip), %rcx
	call	_Z4readIiEvRT_
	movl	t(%rip), %eax
	testl	%eax, %eax
	jle	.L73
	leaq	96(%rsp), %rax
	leaq	T(%rip), %rsi
	movl	$1, %ebx
	movq	%rax, 40(%rsp)
	leaq	2138416(%rsp), %rax
	movq	%rax, 56(%rsp)
.L70:
	movq	40(%rsp), %rcx
	addl	$1, %ebx
	call	_Z4readIiEvRT_
	movq	56(%rsp), %rcx
	call	_Z4readIiEvRT_
	movl	96(%rsp), %ecx
	movl	2138416(%rsp), %eax
	leal	-1(%rcx), %edx
	subl	$1, %eax
	cltq
	movslq	%edx, %rdx
	movq	%rdx, %rcx
	salq	$7, %rcx
	addq	%rdx, %rcx
	leaq	(%rdx,%rcx,4), %rdx
	addq	%rdx, %rax
	cmpl	%ebx, t(%rip)
	movq	$1, (%rsi,%rax,8)
	jge	.L70
.L73:
	movl	k(%rip), %r15d
	testl	%r15d, %r15d
	jle	.L132
	leaq	96(%rsp), %rax
	movl	$0, 68(%rsp)
	movq	%rax, 40(%rsp)
	leaq	2138416(%rsp), %rax
	movq	%rax, 56(%rsp)
.L91:
	movq	40(%rsp), %rcx
	xorl	%edx, %edx
	movl	$2138312, %r8d
	call	memset
	movl	%r15d, %ecx
	movl	$1, %eax
	sall	%cl, %eax
	testl	%eax, %eax
	movl	%eax, %r15d
	jle	.L75
	leal	-1(%rax), %eax
	leaq	T(%rip), %rbp
	leaq	A(%rip), %r13
	movl	$0, 48(%rsp)
	movq	%rax, %r9
	movq	%rax, 88(%rsp)
	addq	$1, %rax
	movq	%rax, 80(%rsp)
	movq	%rbp, %r14
	imulq	$4136, %rax, %rax
	movq	%rax, 72(%rsp)
	addq	%rax, %r13
.L76:
	xorl	%r12d, %r12d
.L80:
	movq	(%r14,%r12,8), %r10
	testq	%r10, %r10
	je	.L77
	movl	48(%rsp), %esi
	leaq	A(%rip), %rbx
	leal	(%r15,%r12), %r11d
	.p2align 4,,10
.L78:
	movl	%esi, %eax
	movl	%r12d, %edx
	movq	%rbx, %rcx
	andl	%r9d, %eax
	cltq
	movq	%rax, %r8
	salq	$7, %r8
	addq	%rax, %r8
	leaq	(%rax,%r8,4), %r8
	.p2align 4,,10
.L79:
	movl	%edx, %eax
	movq	%r10, %rdi
	addl	$1, %edx
	imulq	(%rcx), %rdi
	andl	%r9d, %eax
	addq	$8, %rcx
	cltq
	addq	%r8, %rax
	xorq	%rdi, 96(%rsp,%rax,8)
	cmpl	%edx, %r11d
	jne	.L79
	addq	$4136, %rbx
	addl	$1, %esi
	cmpq	%r13, %rbx
	jne	.L78
.L77:
	addq	$1, %r12
	cmpq	%r12, 80(%rsp)
	jne	.L80
	addl	$1, 48(%rsp)
	addq	$4136, %r14
	movl	48(%rsp), %eax
	cmpl	%r15d, %eax
	jne	.L76
	movq	40(%rsp), %rdx
	leaq	A(%rip), %rcx
	movl	$2138312, %r8d
	call	memcpy
	movq	88(%rsp), %rax
	leaq	T(%rip), %rcx
	addq	72(%rsp), %rcx
	xorl	%edx, %edx
	leaq	8(,%rax,8), %r10
.L95:
	leaq	(%r10,%rbp), %r9
	movq	%rbp, %rax
.L82:
	xorl	%r8d, %r8d
	cmpq	$0, (%rax)
	setg	%r8b
	addq	$8, %rax
	addl	%r8d, %edx
	cmpq	%rax, %r9
	jne	.L82
	addq	$4136, %rbp
	cmpq	%rcx, %rbp
	jne	.L95
	jmp	.L83
.L131:
	leaq	rbuf(%rip), %rax
	movq	%rax, p1(%rip)
	movq	40(%rsp), %rax
	call	*%rax
	leaq	rbuf(%rip), %rcx
	movl	$1, %edx
	movq	%rax, %r9
	movl	$8388608, %r8d
	call	fread
	leaq	(%rax,%rbp), %rdx
	movq	p1(%rip), %rax
	movq	%rdx, p2(%rip)
	cmpq	%rax, %rdx
	jne	.L60
	movl	$-1, %r8d
	jmp	.L59
.L130:
	leaq	rbuf(%rip), %rax
	movq	%rax, p1(%rip)
	call	*__imp___iob_func(%rip)
	leaq	rbuf(%rip), %rcx
	movl	$1, %edx
	movq	%rax, %r9
	movl	$8388608, %r8d
	call	fread
	leaq	(%rax,%rbp), %rdx
	movq	p1(%rip), %rax
	movq	%rdx, p2(%rip)
	cmpq	%rax, %rdx
	jne	.L57
	movl	$-1, %r8d
	jmp	.L58
.L75:
	movq	40(%rsp), %rdx
	leaq	A(%rip), %rcx
	movl	$2138312, %r8d
	call	memcpy
	xorl	%edx, %edx
.L83:
	cmpl	%edx, t(%rip)
	jge	.L84
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	movl	$75, %r8d
	call	_assert
.L84:
	movq	56(%rsp), %rcx
	xorl	%edx, %edx
	movl	$2138312, %r8d
	addl	$1, 68(%rsp)
	movl	$1, %r13d
	call	memset
	movl	k(%rip), %r15d
	movl	%r15d, %ecx
	sall	%cl, %r13d
	testl	%r13d, %r13d
	jle	.L85
	leal	-1(%r13), %eax
	movl	$0, 48(%rsp)
	movq	%rax, %r10
	addq	$1, %rax
	imulq	$4136, %rax, %r12
	movq	%rax, 72(%rsp)
	leaq	T(%rip), %rax
	movq	%rax, %r14
	addq	%rax, %r12
.L86:
	xorl	%ebp, %ebp
.L90:
	movq	(%r14,%rbp,8), %r9
	testq	%r9, %r9
	je	.L87
	movl	48(%rsp), %esi
	leaq	T(%rip), %rbx
	leal	0(%r13,%rbp), %r11d
	.p2align 4,,10
.L88:
	movl	%esi, %eax
	movl	%ebp, %edx
	movq	%rbx, %rcx
	andl	%r10d, %eax
	cltq
	movq	%rax, %r8
	salq	$7, %r8
	addq	%rax, %r8
	leaq	(%rax,%r8,4), %r8
	.p2align 4,,10
.L89:
	movl	%edx, %eax
	movq	%r9, %rdi
	addl	$1, %edx
	imulq	(%rcx), %rdi
	andl	%r10d, %eax
	addq	$8, %rcx
	cltq
	addq	%r8, %rax
	xorq	%rdi, 2138416(%rsp,%rax,8)
	cmpl	%r11d, %edx
	jne	.L89
	addq	$4136, %rbx
	addl	$1, %esi
	cmpq	%r12, %rbx
	jne	.L88
.L87:
	addq	$1, %rbp
	cmpq	72(%rsp), %rbp
	jne	.L90
	addl	$1, 48(%rsp)
	addq	$4136, %r14
	movl	48(%rsp), %eax
	cmpl	%r13d, %eax
	jne	.L86
.L85:
	movq	56(%rsp), %rdx
	leaq	T(%rip), %rcx
	movl	$2138312, %r8d
	call	memcpy
	cmpl	%r15d, 68(%rsp)
	jl	.L91
.L74:
	testl	%r13d, %r13d
	jle	.L100
	leal	-1(%r13), %eax
	leaq	A(%rip), %rcx
	xorl	%edx, %edx
	leaq	1(%rax), %r8
	leaq	8(,%rax,8), %r9
	imulq	$4136, %r8, %r8
	addq	%rcx, %r8
.L93:
	leaq	(%r9,%rcx), %r10
	movq	%rcx, %rax
.L94:
	xorl	%r11d, %r11d
	cmpq	$0, (%rax)
	setg	%r11b
	addq	$8, %rax
	addl	%r11d, %edx
	cmpq	%rax, %r10
	jne	.L94
	addq	$4136, %rcx
	cmpq	%r8, %rcx
	jne	.L93
	jmp	.L92
.L100:
	xorl	%edx, %edx
.L92:
	leaq	.LC2(%rip), %rcx
	call	_Z6printfPKcz
	xorl	%eax, %eax
	addq	$4276744, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L132:
	movl	$1, %eax
	movl	%r15d, %ecx
	sall	%cl, %eax
	movl	%eax, %r13d
	jmp	.L74
	.seh_endproc
	.p2align 4,,15
	.def	_GLOBAL__sub_I_rbuf;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_rbuf
_GLOBAL__sub_I_rbuf:
.LFB3735:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
	leaq	A(%rip), %rcx
	xorl	%edx, %edx
	movl	$2138312, %r8d
	call	memset
	leaq	T(%rip), %rcx
	movl	$2138312, %r8d
	xorl	%edx, %edx
	addq	$40, %rsp
	jmp	memset
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_rbuf
	.globl	T
	.bss
	.align 64
T:
	.space 2138312
	.globl	A
	.align 64
A:
	.space 2138312
	.globl	t
	.align 4
t:
	.space 4
	.globl	k
	.align 4
k:
	.space 4
	.globl	p3
	.data
	.align 8
p3:
	.quad	wbuf
	.globl	wbuf
	.bss
	.align 64
wbuf:
	.space 8388608
	.globl	p2
	.data
	.align 8
p2:
	.quad	rbuf
	.globl	p1
	.align 8
p1:
	.quad	rbuf
	.globl	rbuf
	.bss
	.align 64
rbuf:
	.space 8388608
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__mingw_vprintf;	.scl	2;	.type	32;	.endef
	.def	fread;	.scl	2;	.type	32;	.endef
	.def	_ZNSs12_M_leak_hardEv;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	fwrite;	.scl	2;	.type	32;	.endef
	.def	memset;	.scl	2;	.type	32;	.endef
	.def	memcpy;	.scl	2;	.type	32;	.endef
	.def	_assert;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef)");